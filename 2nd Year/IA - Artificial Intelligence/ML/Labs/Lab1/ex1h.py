import numpy as np
v_img=[]
for i in range(0,9):
    imgpath="images\car_"+str(i)+".npy"
    image = np.load(imgpath)
    v_img.append(image)
print(np.array(v_img))

v_img = v_img[200:300, 280:400]

print(v_img)