def accept_array():
    n = int(input("Enter the total number of students: "))
    print("Input roll numbers in sorted order")
    A = [int(input(f"Enter the roll no of student {i + 1}: ")) for i in range(n)]
    print("Student Info accepted successfully\n\n")
    return A, n

def display_array(A):
    if not A:
        print("\nNo records in the database")
    else:
        print("Students Array:", ' '.join(map(str, A)))
        print("\n")

def recursive_binary_search(A, s, l, X):
    if s <= l:
        mid = (s + l) // 2
        if A[mid] == X:
            return mid  # Found
        elif X < A[mid]:
            return recursive_binary_search(A, s, mid - 1, X)
        else:
            return recursive_binary_search(A, mid + 1, l, X)
    return -1  # NOT FOUND

def iterative_binary_search(A, n, X):
    s, l = 0, n - 1
    while s <= l:
        mid = (s + l) // 2
        if A[mid] == X:
            return mid  # Found
        elif X < A[mid]:
            l = mid - 1
        else:
            s = mid + 1
    return -1  # NOT FOUND

def fibonacci_search(A, n, X):
    f1, f2 = 0, 1
    while f2 < n:
        f1, f2 = f2, f1 + f2
    offset = -1
    while f2 > 1:
        i = min(offset + f1, n - 1)
        if A[i] == X:
            return i  # Found
        elif X < A[i]:
            f2, f1 = f1, f2 - f1
        else:
            f1, f2 = f2, f1
            offset = i
    if f2 == 1 and offset + 1 < n and A[offset + 1] == X:
        return offset + 1  # Found
    return -1  # NOT FOUND

def main():
    A = []
    while True:
        print("\t1 : Accept & Display Students info ")
        print("\t2 : Recursive Binary Search")
        print("\t3 : Iterative Binary Search")
        print("\t4 : Fibonacci Search")
        print("\t5 : Exit")
        ch = int(input("Enter your choice: "))
        
        if ch == 5:
            print("End of Program")
            break

        elif ch == 1:
            A, n = accept_array()
            display_array(A)

        elif ch == 2:
            X = int(input("Enter the roll_no to be searched: "))
            flag = recursive_binary_search(A, 0, n - 1, X)
            if flag == -1:
                print("\tRoll no to be searched not found\n")
            else:
                print(f"\tRoll no found at location {flag + 1}")

        elif ch == 3:
            X = int(input("Enter the roll_no to be searched: "))
            flag = iterative_binary_search(A, n, X)
            if flag == -1:
                print("\tRoll no to be searched not found\n")

        elif ch == 4:
            X = int(input("Enter the roll_no to be searched: "))
            flag = fibonacci_search(A, n, X)
            if flag == -1:
                print("\tRoll no to be searched not found\n")
            else:
                print(f"\tRoll no found at location {flag + 1}")

        else:
            print("Wrong choice entered!! Try again")

if __name__ == "__main__":
    main()
