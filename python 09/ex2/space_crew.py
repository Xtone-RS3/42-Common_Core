from enum import Enum
from pydantic import BaseModel, Field, model_validator
from datetime import datetime


class Rank(Enum):
    cadet: str = "cadet"
    officer: str = "officer"
    lieutenant: str = "lieutenant"
    captain: str = "captain"
    commander: str = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = Field(True)


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = Field("planned")
    budget_millions: float = Field(ge=1, le=10000)

    @model_validator(mode="after")
    def validator_func(self):
        rank_list = []
        experienced_list = []
        inactive_list = []
        for crewmate in self.crew:
            rank_list.append(crewmate.rank)
            if crewmate.years_experience >= 5:
                experienced_list.append(crewmate.name)
            if not crewmate.is_active:
                inactive_list.append(crewmate.name)
        if not self.mission_id.startswith("M"):
            raise Exception("Mission ID must start with 'M'")
        if Rank("commander") not in rank_list and Rank("captain") not in rank_list:  # noqa: E501
            raise Exception("Mission must have at least one Commander or Captain")  # noqa: E501
        if self.duration_days > 365:
            if (len(experienced_list) / len(self.crew)) < 0.5:
                raise Exception("Long missions (> 365 days) need 50% experienced crew (5+ years)")  # noqa: E501
        if len(inactive_list) != 0:
            raise Exception("All crew members must be active")
        return self


if __name__ == "__main__":
    sarah2015 = CrewMember(
        member_id="CM001",
        name="Sarah Williams",
        rank=Rank("captain"),
        age=43,  # sniper
        specialization="Mission Command",
        years_experience=19,
        is_active=True
    )
    forsenSenor = CrewMember(
        member_id="CM002",
        name="James Hernandez",
        rank=Rank("captain"),
        age=43,
        specialization="Pilot",
        years_experience=30,
        is_active=True
    )
    flushE = CrewMember(
        member_id="CM003",
        name="Anna Jones",
        rank=Rank("cadet"),
        age=35,
        specialization="Communications",
        years_experience=15,
        is_active=True
    )
    forsenAlright = CrewMember(
        member_id="CM004",
        name="David Smith",
        rank=Rank("commander"),
        age=27,
        specialization="Security",
        years_experience=15,
        is_active=True
    )
    forsenCD = CrewMember(
        member_id="CM005",
        name="Maria Jones",
        rank=Rank("cadet"),
        age=55,
        specialization="Research",
        years_experience=30,
        is_active=True
    )
    forsenNotLookingAtYou = CrewMember(
        member_id="CM006",
        name="Sebastian Fors",
        rank=Rank("cadet"),
        age=55,
        specialization="Research",
        years_experience=0,
        is_active=True
    )
    angrE = CrewMember(
        member_id="CM007",
        name="Peppah Fors",
        rank=Rank("cadet"),
        age=18,
        specialization="Research",
        years_experience=0,
        is_active=True
    )
    usf = SpaceMission(
        mission_id="M2024_TITAN",
        mission_name="Solar Observatory Research Mission",
        destination="Solar Observatory",
        launch_date="2024-03-30T00:00:00",
        duration_days=451,
        crew=[sarah2015, forsenSenor, flushE, forsenAlright, forsenCD],
        mission_status="planned",
        budget_millions=2208.1
    )
    print("Space Mission Crew Validation")
    print("=========================================")
    print("Valid mission created:")
    print(
        "Mission:",
        usf.mission_id
    )
    print(
        "ID:",
        usf.mission_id
    )
    print(
        "Destination:",
        usf.destination
    )
    print(
        "Duration:",
        usf.duration_days
    )
    print(
        "Budget:",
        f"${usf.budget_millions}M"
    )
    print(
        "Crew size:",
        len(usf.crew)
    )
    print("Crew members:")
    for crewmate in usf.crew:
        print(
            "-",
            crewmate.name,
            f"({crewmate.rank.name})",
            f"- {crewmate.specialization}"
        )
    print()
    print("=========================================")
    print("Expected validation error:")
    try:
        asf = SpaceMission(
            mission_id="M2025_TITAN",
            mission_name="Solar Observatory Research Mission",
            destination="Solar Observatory",
            launch_date="2024-03-30T00:00:00",
            duration_days=451,
            crew=[forsenNotLookingAtYou, sarah2015, angrE],
            mission_status="planned",
            budget_millions=2208.1
        )
    except Exception as e:
        print(e)
