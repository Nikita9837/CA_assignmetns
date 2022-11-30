import cv2
import numpy as np
import matplotlib.pyplot as plt

flower = cv2.imread("image.jpg")
flower = cv2.resize(flower, (800,600))

# cv2.imshow('original', flower)
# cv2.waitKey(0)

s = flower.shape
# print(s)

flowerGray = cv2.cvtColor(flower, cv2.COLOR_BGR2GRAY)
# cv2.imshow('Binary', flower)
flowerGray = cv2.convertScaleAbs(flowerGray, alpha=1.10, beta=-20)
# cv2.imshow('Enhance', flowerGray)
# cv2.waitKey(0)

H = np.zeros(shape=(256,1))
# print(H)

for i in range(s[0]):
    for j in range(s[1]):
        k=flowerGray[i,j]
        H[k,0]=H[k,0]+1

print(H)
plt.plot(H)
plt.show()