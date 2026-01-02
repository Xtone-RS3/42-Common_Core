import sys

if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    if len(sys.argv) == 1:
        print("No scores provided. Usage: python3 ft_score_analytics.py\
 <score1> <score2> ...")
    else:
        arr = []
        for num in sys.argv[1:]:
            try:
                arr.append(int(num))
            except ValueError:
                print("Error: Invalid score")
                sys.exit(1)
        print("Scores proccessed: [", end="")
        x = 1
        avg = 0
        for score in sys.argv[1:]:
            x += 1
            if x != len(sys.argv):
                print(score, end=", ")
            else:
                print(score, end="")
        print("]")
        print(f"Total players: {len(sys.argv)-1}")
        print(f"Total score: {sum(arr)}")
        print(f"Average score: {sum(arr)/(x-1)}")
        print(f"High score: {max(arr)}")
        print(f"Low score: {min(arr)}")
        print(f"Score range: {max(arr)-min(arr)}")
