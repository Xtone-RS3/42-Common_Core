from abc import ABC, abstractmethod
from typing import Any, List, Dict, Union, Optional


class DataStream(ABC):
    def __init__(self, stream_id: str):
        self.stream_id = stream_id
        self.total_batches = 0
        self.total_items = 0

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        return_list = []
        for data in data_batch:
            if data.startswith(criteria):
                return_list.append(data)
        return return_list

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {
            "stream_id": self.stream_id,
            "total_batches": self.total_batches,
            "total_items": self.total_items
        }

    def record_batch(self, data_batch: List[Any]):
        self.total_batches += 1
        self.total_items += len(data_batch)


class SensorStream(DataStream):
    def process_batch(self, data_batch: List[Any]) -> str:
        stats = [0, 0]
        for data in data_batch:
            if data[:5] == "temp:":
                stats[0] += float(data[5:])
                stats[1] += 1
        if stats[1] == 0:
            stats[1] = 1
        super().record_batch(data_batch)
        return f"Sensor analysis: {len(data_batch)} readings processed, avg\
 temp: {stats[0]/stats[1]}°C"

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        return_list = []
        for data in data_batch:
            if data.startswith(criteria):
                return_list.append(data)
        return return_list

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {
            "stream_id": self.stream_id,
            "type": "Sensor",
            "total_batches": self.total_batches,
            "total_readings": self.total_items,
        }


class TransactionStream(DataStream):
    def process_batch(self, data_batch: List[Any]) -> str:
        net = 0
        for data in data_batch:
            if data.startswith("buy:"):
                net += int(data[4:])
            else:
                net -= int(data[5:])
        super().record_batch(data_batch)
        return f"Transaction analysis: {len(data_batch)} operations, net flow:\
 {net} units"

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        return_list = []
        for data in data_batch:
            if data.startswith(criteria):
                return_list.append(data)
        return return_list

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {
            "stream_id": self.stream_id,
            "type": "Transaction",
            "total_batches": self.total_batches,
            "total_operations": self.total_items,
        }


class EventStream(DataStream):
    def process_batch(self, data_batch: List[Any]) -> str:
        err_count = 0
        for data in data_batch:
            if data == "error":
                err_count += 1
        super().record_batch(data_batch)
        return f"Event analysis: {len(data_batch)} events, {err_count} error\
 detected"

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        return_list = []
        for data in data_batch:
            if data.startswith(criteria):
                return_list.append(data)
        return return_list

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {
            "stream_id": self.stream_id,
            "type": "Event",
            "total_batches": self.total_batches,
            "total_events": self.total_items,
        }


class StreamProcessor:
    def __init__(self, streams: List[DataStream]):
        self.streams = streams

    def process_batches(self, batches: Dict[str, List[Any]]) -> Dict:
        results = {}
        for stream in self.streams:
            batch = batches.get(stream.stream_id, [])
            results[stream.stream_id] = stream.process_batch(batch)
        return results


if __name__ == "__main__":
    print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===\n")

    # Initialize streams
    sensor = SensorStream("SENSOR_001")
    transaction = TransactionStream("TRANS_001")
    event = EventStream("EVENT_001")

    print("Initializing Sensor Stream...")
    print(f"Stream ID: {sensor.stream_id}, Type: Environmental Data")
    sensor_data = ["temp:22.5", "humidity:65", "pressure:1013"]
    print("Processing sensor batch:", sensor_data)
    print(sensor.process_batch(sensor_data))
    print()

    print("Initializing Transaction Stream...")
    print(f"Stream ID: {transaction.stream_id}, Type: Financial Data")
    transaction_data = ["buy:100", "sell:150", "buy:75"]
    print("Processing transaction batch:", transaction_data)
    print(transaction.process_batch(transaction_data))
    print()

    print("Initializing Event Stream...")
    print(f"Stream ID: {event.stream_id}, Type: System Events")
    event_data = ["login", "error", "logout"]
    print("Processing event batch:", event_data)
    print(event.process_batch(event_data))
    print()

    # Create processor
    processor = StreamProcessor([sensor, transaction, event])

    # Sample batches
    batches_list = [
        {
            "SENSOR_001": ["temp:22.5", "humidity:65", "pressure:1013"],
            "TRANS_001": ["buy:100", "sell:150", "buy:75"],
            "EVENT_001": ["login", "error", "logout"]
        },
        {
            "SENSOR_001": ["temp:23.0", "humidity:60"],
            "TRANS_001": ["sell:50", "buy:200", "sell:25", "buy:100"],
            "EVENT_001": ["login", "logout", "error"]
        }
    ]

    print("=== Polymorphic Stream Processing ===")
    print("Processing mixed stream types through unified interface...\n")

    for i, batches in enumerate(batches_list, start=1):
        print(f"Batch {i} Results:")
        results = processor.process_batches(batches)
        for stream_id, output in results.items():
            if stream_id == "SENSOR_001":
                print(f"- Sensor data: {len(batches[stream_id])}\
 readings processed")
            elif stream_id == "TRANS_001":
                print(f"- Transaction data: {len(batches[stream_id])}\
 operations processed")
            elif stream_id == "EVENT_001":
                print(f"- Event data: {len(batches[stream_id])}\
 events processed")
        print()

    print("Stream filtering active: High-priority data only")
    # Assuming filter_data is implemented correctly
    filtered_sensor = sensor.filter_data(batches_list[1]["SENSOR_001"], "temp")
    filtered_trans = transaction.filter_data(
        batches_list[1]["TRANS_001"], "buy")
    print(f"Filtered results: {len(filtered_sensor)} critical sensor alerts,\
 {len(filtered_trans)} large transactions\n")

    print("All streams processed successfully. Nexus throughput optimal.")
