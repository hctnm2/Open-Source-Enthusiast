import cv2

face_cascade=cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

img=cv2.imread("hum.jpg")       # not passing any 2nd parameter , that means image is being read as color image

# greyscale image is more accurate 
# at the end coloured image will be shown 
# use the gray image to pass it to the method that will be seaching for the face , create a gray image variable where store the grayscale version of the image 

gray_img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)        # conversion of colored to gray 

# DETECT MULTISCALE METHOD :: search for the cascade classifier so it 
# parameter specifying how much the i,age size is reduced at eacg image sacle
faces=face_cascade.detectMultiScale(gray_img,
scaleFactor=1.1,
minNeighbors=5)

# DRAW RECTANGLE ON FACE

# cv2.rectangle(resized_image,pointone(),pointtwo(),color(),thickness)
for x, y, w, h in faces:
    img=cv2.rectangle(img, (x,y), (x+w,y+h), (0,255,0), 3)      # BLUE =0 , GREEN =255 , RED=0

# this x y w h is from the list [276 , 171, 302 , 302] [x, y, w ,h]

print(type(faces))
print(faces)                    #[276 171 302 302] [276th column 171th row  302 height 302 width] 1st point of rectangle at row and column , and rectangle with height and width.

resized_image=cv2.resize(img,(int(img.shape[1]/3), int(img.shape[0]/3)))

cv2.imshow("Gray",resized_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
















































