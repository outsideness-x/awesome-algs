def insert_sort(arr):
    for k in range(1, len(arr)):
        key = arr[k]  # element to be inserted
        j = k - 1  # index of the last element of a sorted part

    # move elements of arr[0..j] that are greater than key    
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

    return arr

# check
arr1 = [3, 5, 1, 8, 11, 9, 6]
arr1_sorted = insert_sort(arr1)
print(arr1_sorted)