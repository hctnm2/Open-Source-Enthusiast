
from tkinter import *
from datetime import date

root = Tk()
root.geometry("700x500")
root.title("Age calculator")


def calculating():
    try:
        today = date.today()
        birthDate = date(int(yearEntry.get()),
                         int(monthEntry.get()), int(dayEntry.get()))
        age = today.year - birthDate.year - ((today.month, today.day) < (birthDate.month, birthDate.day))
        Label(text=f"{nameValue.get()} your age is {age}",fg="lime").grid(row=7, column=1)
    except:
        Label(text=f"Enter a valid data ",fg="red").grid(row=7, column=1)


Label(text="Enter your Release Date").grid(row=1, column=1,pady=10)
Label(text="Name").grid(row=2, column=0, padx=90)
Label(text="Year").grid(row=3, column=0)
Label(text="Month").grid(row=4, column=0)
Label(text="Day").grid(row=5, column=0)
nameValue = StringVar()
yearValue = StringVar()
monthValue = StringVar()
dayValue = StringVar()
nameEntry = Entry(root, textvariable=nameValue)
yearEntry = Entry(root, textvariable=yearValue)
monthEntry = Entry(root, textvariable=monthValue)
dayEntry = Entry(root, textvariable=dayValue)

nameEntry.grid(row=2, column=1, pady=10)
yearEntry.grid(row=3, column=1, pady=10)
monthEntry.grid(row=4, column=1, pady=10)
dayEntry.grid(row=5, column=1, pady=10)
Button(text="Calculate Age", command=calculating).grid(row=6, column=1, pady=10)

root.mainloop()