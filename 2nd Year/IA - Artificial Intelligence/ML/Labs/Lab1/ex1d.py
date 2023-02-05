import numpy as np
v_img = []
sum = 0
index = -1
for i in range(0, 9):
    imgpath = "images\car_"+str(i)+".npy"
    image = np.load(imgpath)
    v_img.append(image)
    if np.sum(image) > sum:
        sum = np.sum(image)
        index = i
print(sum)
print(index)
