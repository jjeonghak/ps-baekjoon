def move_disk(start_peg, end_peg):
    print("{} {}".format(start_peg, end_peg))


def hanoi(num_disks, start_peg, end_peg):
    if num_disks == 1:
        move_disk(start_peg, end_peg)
        return

    middle_peg = 6 - (start_peg + end_peg)
    hanoi(num_disks - 1, start_peg, middle_peg)
    move_disk(start_peg, end_peg)
    hanoi(num_disks - 1, middle_peg, end_peg)


def hanoical(n):
    if n == 1:
        return 1
    return 2 * hanoical(n - 1) + 1


def main():
    n = int(input())
    print(hanoical(n))
    if n<=20:
        hanoi(n, 1, 3)


if __name__ == "__main__":
    main()
