def ft_count_harvest_recursive(target=0, day=0):
    if target == 0:
        target = int(input("Days until harvest: "))
        ft_count_harvest_recursive(target, day)
    else:
        print("Day ", end='')
        day = day + 1
        print(day)
        if day == target:
            print("Harvest time!")
        else:
            return (ft_count_harvest_recursive(target, day))
