from enum import Enum
from pydantic import BaseModel, Field, model_validator  # noqa: F401
from datetime import datetime
from typing import Optional


class ContactType(Enum):
    radio: str = "radio"
    visual: str = "visual"
    physical: str = "physical"
    telepathic: str = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0, le=10)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: Optional[str] = Field(None, max_length=500)
    is_verified: bool = Field(False)

    @model_validator(mode="after")
    def validator(self):
        if not self.contact_id.startswith("AC"):
            raise Exception
        if self.contact_type == ContactType("physical"):
            if not self.is_verified:
                raise Exception("Physical contacts require verification")
        elif self.contact_type == ContactType("telepathic"):
            if not self.witness_count >= 3:
                raise Exception("Telepathic contacts require 3+ witnesses")
        if self.signal_strength > 7:
            if not self.message_received:
                raise Exception("Strong signal (>7) requires a message")
        return self


if __name__ == "__main__":
    print("Alien Contact Log Validation")
    print("======================================")
    ayylmao_contact = AlienContact(
        contact_id="AC_2024_001",
        timestamp=datetime.now(),
        location="my mums car",
        contact_type=ContactType("radio"),
        signal_strength=6,
        duration_minutes=69,
        witness_count=4,
        message_received="ayyyyy lmaoooo",
        is_verified=True
    )
    print("Valid contact report:")
    print(
        "ID:",
        ayylmao_contact.contact_id
    )
    print(
        "Type:",
        ayylmao_contact.contact_type
    )
    print(
        "Location:",
        ayylmao_contact.location
    )
    print(
        "Signal: ",
        ayylmao_contact.signal_strength,
        "/10",
        sep=""
    )
    print(
        "Duration:",
        ayylmao_contact.duration_minutes,
        "minutes"
    )
    print(
        "Witness:",
        ayylmao_contact.witness_count
    )
    print(
        "Message:",
        ayylmao_contact.message_received
    )
    print()
    print("======================================")
    print("Expected validation error:")
    try:
        ayylmao_contact = AlienContact(
            contact_id="AC_2024_001",
            timestamp=datetime.now(),
            location="my mums car",
            contact_type=ContactType("telepathic"),
            signal_strength=6,
            duration_minutes=69,
            witness_count=2,
            message_received="ayyyyy lmaoooo",
            is_verified=True
        )
    except Exception as e:
        print(e)
