def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    left_part = arr[:mid]
    right_part = arr[mid:]

    left_part = merge_sort(left_part)
    right_part = merge_sort(right_part)

    return merge(left_part, right_part)

def merge(left, right):
    sorted_array = []
    i = 0
    j = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            sorted_array.append(left[i])
            i += 1
        else:
            sorted_array.append(right[j])
            j += 1

    while i < len(left):
        sorted_array.append(left[i])
        i += 1

    while j < len(right):
        sorted_array.append(right[j])
        j += 1

    return sorted_array
    
user_arr = [2, 5, 7, 1, 3, 11, 9, 10, 6, 4]
res_arr = merge_sort(user_arr)
print(res_arr)