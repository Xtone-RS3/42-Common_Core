if __name__ == "__main__":
    print("=== Player Inventory System ===")
    print()
    print("=== Alice's Inventory ===")
    alice = dict({
     "rune sword": {
        "Type": "weapon",
        "Rarity": "rare",
        "Qty": 1,
        "Price": 500},
     "bronze sword": {
        "Type": "weapon",
        "Rarity": "common",
        "Qty": 2,
        "Price": 10},
     "potion": {
        "Type": "consumable",
        "Rarity": "common",
        "Qty": 5,
        "Price": 50},
     "shield": {
        "Type": "armor",
        "Rarity": "uncommon",
        "Qty": 1,
        "Price": 200}
    })
    bob = dict({
     "the one ring": {
        "Type": "weapon",
        "Rarity": "rare",
        "Qty": 1,
        "Price": 500},
     "potion": {
        "Type": "consumable",
        "Rarity": "common",
        "Qty": 0,
        "Price": 50}
    })
    for key in alice.keys():
        print(f"{key} ({alice[key]['Type']}, {alice[key]['Rarity']}):\
 {alice[key]['Qty']}x @\
 {alice[key]['Price']} gold each = {alice[key]['Qty'] * alice[key]['Price']}")
    print()

    total_val = 0
    for item_name, item_data in alice.items():
        total_val += item_data['Qty'] * item_data['Price']
    print(f"Inventory value: {total_val}")

    total_count = 0
    for item_name, item_data in alice.items():
        total_count += item_data["Qty"]
    print(f"Item count: {total_count} items")

    category_count = dict({"weapon": 0, "consumable": 0, "armor": 0})
    for item_name, item_data in alice.items():
        category_count[item_data['Type']] += item_data['Qty']
    print(f"Categories: weapon({category_count['weapon']}),\
 consumable({category_count['consumable']}), armor({category_count['armor']})")
    print()

    print("=== Transaction: Alice gives Bob 2 potions ===")
    alice["potion"]["Qty"] -= 2
    bob["potion"]["Qty"] += 2
    print("Transaction successful!")
    print()

    print("=== Updated Inventories ===")
    print(f"Alice potions: {alice['potion']['Qty']}")
    print(f"Bob potions: {bob['potion']['Qty']}")
    print()

    print("=== Inventory Analytics ===")
    total_val = 0
    for item_name, item_data in alice.items():
        total_val += item_data['Qty'] * item_data['Price']
    print(f"Inventory value: {total_val}")
    print(f"MVP: Alice ({total_val} gold)")
    total_count = 0
    for item_name, item_data in alice.items():
        total_count += item_data["Qty"]
    print(f"Item count: {total_count} items")
    print(f"Most items: Alice ({total_count} items)")
    print("Rarest items: ", end="")
    printed = False
    for inventory in (alice, bob):
        for item_name, item_data in inventory.items():
            if item_data["Rarity"] == "rare":
                if printed:
                    print(", ", end="")
                    printed = False
                print(item_name, end="")
                printed = True
    print()

# if __name__ == "__main__":
#     print("=== Player Inventory System ===")
#     print()
#     print("=== Alice's Inventory ===")
#     alice = dict({"rune sword": ["weapon", "rare", 1, 500],
#                   "bronze sword": ["weapon", "common", 2, 10],
#                   "potion": ["consumable", "common", 5, 50],
#                   "shield": ["armor", "uncommon", 1, 200]})
#     bob = dict({"potion": ["consumable", "common", 0, 50],
#                 "the one ring": ["weapon", "rare", 1, 500]})
#     total_val = 0
#     total_qty = 0
#     total_sword = 0
#     total_consume = 0
#     total_arm = 0
#     for key in alice.keys():
#         print(f"{key} ({alice[key][0]}, {alice[key][1]}): {alice[key][2]}x @\
#  {alice[key][3]} gold each = {alice[key][2] * alice[key][3]}")
#         total_val = total_val + alice[key][2] * alice[key][3]
#     print()
#     print(f"Inventory value: {total_val}")
#     for key in alice.keys():
#         total_qty = total_qty + alice[key][2]
#         for category in alice[key]:
#             if category == "weapon":
#                 total_sword = total_sword + alice[key][2]
#             if category == "consumable":
#                 total_consume = total_consume + alice[key][2]
#             if category == "armor":
#                 total_arm = total_arm + alice[key][2]
#     print(f"Item count: {total_qty} items")
#     print(f"Categories: weapon({total_sword}), consumables({total_consume}),\
#  armor({total_arm})")
#     print()
#     print("=== Transaction: Alice gives Bob 2 potions ===")
#     alice["potion"][2] -= 2
#     total_qty -= 2
#     total_val -= 2 * alice["potion"][3]
#     bob["potion"][2] += 2
#     print("Transaction successful!")
#     print()
#     print("=== Updated Inventories ===")
#     print(f"Alice potions: {alice['potion'][2]}")
#     print(f"Bob potions: {bob['potion'][2]}")
#     print()
#     print("=== Inventory Analytics ===")
#     print(f"MVP: Alice ({total_val} gold)")
#     print(f"Most items: Alice ({total_qty} items)")
#     print("Rarest items: ", end="")
#     printed = False
#     for key in alice.keys():
#         if alice[key][1] == "rare":
#             if printed:
#                 print(", ", end="")
#                 printed = False
#             print(key, end="")
#             printed = True
#     for key in bob.keys():
#         if bob[key][1] == "rare":
#             if printed:
#                 print(", ", end="")
#                 printed = False
#             print(key, end="")
#             printed = True
#     print()
