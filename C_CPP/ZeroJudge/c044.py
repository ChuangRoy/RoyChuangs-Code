from math import ceil, floor
n = int(input())
data_str = ""
for _ in range(n):
    data_str += str(input())

data_list = [0] * 26
for i in data_str:
    if ord('A') <= ord(i) and ord(i) <= ord('Z'):
        data_list[ord(i) - ord('A')] += 1
    elif ord('a') <= ord(i) and ord(i) <= ord('z'):
        data_list[ord(i) - ord('a')] += 1
# print(data_list)
output_list = []
for i in range(26):
    if data_list[i] > 0:
        output_list.append(data_list[i] + 1.0-i/256)

output_list.sort(reverse=1)
# print(output_list)
for i in output_list:
    print(chr(65 + ceil(i)*256 - int(i*256)), ceil(i)-1)
