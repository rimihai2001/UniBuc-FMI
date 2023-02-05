from skimage import io
import matplotlib.pyplot as plt
import numpy as np

v_img=[]
for i in range(0,9):
    imgpath="images\car_"+str(i)+".npy"
    image = np.load(imgpath)
    v_img.append(image)

mean_image = np.mean(np.array(v_img), axis=0) 
dev_std = np.std(v_img)

print((v_img-mean_image)/dev_std)
