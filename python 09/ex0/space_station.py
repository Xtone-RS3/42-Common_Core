from pydantic import BaseModel, Field, model_validator  # noqa: F401
from datetime import datetime
from typing import Optional


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=1, le=100)
    oxygen_level: float = Field(ge=1, le=100)
    last_maintenance: datetime  # DateTime field
    is_operational: bool = Field(True)
    notes: Optional[str] = Field(None, max_length=200)


if __name__ == "__main__":
    print("Space Station Data Validation")
    print("========================================")
    print("Valid station created:")
    try:
        ayylmao_station = SpaceStation(
            station_id="ISS001",
            name="International Space Station",
            crew_size=6,
            power_level=99.9,
            oxygen_level=69,
            last_maintenance=datetime.now(),
            is_operational=True
        )
        print(
            "ID:",
            ayylmao_station.station_id
        )
        print(
            "Name:",
            ayylmao_station.name
        )
        print(
            "Crew:",
            ayylmao_station.crew_size,
            "people"
        )
        print(
            "Power:",
            ayylmao_station.power_level,
            "%"
        )
        print(
            "Oxygen:",
            ayylmao_station.oxygen_level,
            "%"
        )
        if ayylmao_station.is_operational:
            print("Status: Operational")
        else:
            print("Status: Not Operational")
        print()
        print("========================================")
        print("Expected validation error:")
        boring_station = SpaceStation(
            station_id="ISS002",
            name="not cool man...",
            crew_size=21,
            power_level=99.9,
            oxygen_level=69,
            last_maintenance=datetime.now(),
            is_operational=True
        )
    except Exception as e:
        print(e)
