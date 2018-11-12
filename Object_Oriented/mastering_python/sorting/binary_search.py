
def bin_search(array, num, left, right):
    if right >= left:
        midpoint = int(left + (right - left)/2)
        if num == array[midpoint]:
            return midpoint
        elif array[midpoint] > num:
            return bin_search(arr, num, left, midpoint - 1)
        elif array[midpoint] < num: 
            return bin_search(arr, num, midpoint + 1, right)
    else:
        return -1


