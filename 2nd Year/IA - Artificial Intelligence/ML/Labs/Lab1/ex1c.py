import numpy as np
v_img=[]
sum=0
for i in range(0,9):
    imgpath="images\car_"+str(i)+".npy"
    image = np.load(imgpath)
    v_img.append(image)
    print(np.sum(image))
