from tkinter import *

win = Tk()


def kmconv():
    gram = float(e1_v.get())*1000
    pound =float(e1_v.get())*2.20462
    ounces =float(e1_v.get())*35.274
    t2.delete("1.0" , END)
    t2.insert(END,gram)
    t3.delete("1.0" , END)
    t3.insert(END,pound)
    t4.delete("1.0" , END)
    t4.insert(END,ounces)


b1 = Button(win , text="execute" , command=kmconv)
b1.grid(row = 0 ,column =2)


e1_v =StringVar()
e1 = Entry(win ,textvariable=e1_v)
e1.grid(row = 0 ,column =1)

e2 =Label(win, text='kg')
e2.grid(row =0 , column =0)


t2 =Text(win,height=1 , width =20)
t2.grid(row = 1 ,column =0 )

t3 = Text(win ,height=1 , width =20)
t3.grid(row = 1 ,column =1 )

t4 = Text(win ,height=1 , width =20)
t4.grid(row = 1 ,column =2 )


win.mainloop()