from tkinter import *
from tkinter.messagebox import *
import ctypes
#PATH = "C:\msys64\home\Админ\labs\iu7-cprog-labs-2020-sirotkinapolina\lab_12_02_02\\arr.dll"
lib = ctypes.CDLL(PATH)

#void fill_fib(int *arr, int n);
fill_fib = lib.fill_fib
fill_fib.argtypes = (ctypes.POINTER(ctypes.c_long), ctypes.c_int)
fill_fib.restype = None

#int remove_duplicates(int *src, int *dst, int n);
remove_duplicates = lib.remove_duplicates
remove_duplicates.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.c_int)
remove_duplicates.restype = ctypes.c_int

#int unique_count(int *arr, int n);
unique_count = lib.unique_count
unique_count.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
unique_count.restype = ctypes.c_int

current_entry = None

def on_focus(event):
    global current_entry
    current_entry = event.widget
    if (current_entry == dupl_arr_entry):
        fill_arr_entry.delete(0, END)
        data = current_entry.get()
        data = data.split()
        flag = 0
        for i in range(len(data)):
            try:
                data[i] = int(data[i])
            except:
                flag = 1
                break
        if flag == 1:
            showerror("Ошибка", "Каждый элемент массива должен быть целым числом.")
        elif len(data) == 0:
            showerror("Ошибка", "Не введено ни одного элемента массива.")
        else:
            n = len(data)
            res = "Массив, элементами которого являются первые вхождения исходного массива: \n"
            data = (ctypes.c_int * n) (*data)
            #Первый варинт - выделить память под результирующий массив с запасом
            dst = [0 for i in range(n)]
            dst = (ctypes.c_int * n) (*dst)
            k = remove_duplicates(data, dst, n)
            #Второй вариант - сначала узнать количество уникальных элементов, вызвав соответствующую функцию, затем выделить память
            #k = unique_count(data, n)
            #dst = [0 for i in range(k)]
            #dst = (ctypes.c_int * k) (*dst)
            #remove_duplicates(data, dst, n)
            for i in range(k):
                res += str(dst[i]) + " "
            showinfo("Результат", res)
            
    else:
        data = current_entry.get()
        dupl_arr_entry.delete(0, END)
        if (data.isdigit() == False or int(data) == 0):
            showerror("Ошибка", "Должно быть введено целое положительное число.")
            fill_arr_entry.delete(0, END)
        else:
            data = int(data)
            arr = [0 for i in range(data)]
            arr = (ctypes.c_int * data)(*arr)
            fill_fib(arr, data)
            res = "Первые " + str(data) + " чисел Фибоначчи:\n\n"
            for x in arr:
                res += str(x) + " "
            showinfo("Результат", res)

def info():
    showinfo("Справка о программе", "Программа реализует интерфейс для взаимодействия с динамической библиотекой, написаной на языке Си."
             "\nИспользование программы предназначено для ознакомительных целей. Таким образом, рекомендуется использовать небольшие, "
             "наглядные размерности массива."
             "\nВвод данных осуществляется нажатием клавиши Enter. Все введенные данные должны представлять из себя целые числа.")
            

root = Tk()
root.title("Array")
root.geometry('600x380+250+50')
root["bg"] = "#e6f0f0"

canvas = Canvas(width=600, height=500)
canvas["bg"] = "#e6f0f0"
canvas.create_line(0, 180, 800, 180)

remove_duplicates_label = Label(text="Создание нового массива, элементами которого являются первые вхождения\n каждого элемента исходного массива",
                                font = ('Segoe UI', 11, "bold"), background="#e6f0f0")
dupl_arr_label = Label(text="Введите элементы массива: ", background="#e6f0f0", font = ('Segoe UI', 11))
dupl_arr_entry = Entry(font = ('Segoe UI', 14))

fill_fib_label = Label(text="Заполнение массива из N элементов числами Фибоначчи",
                                font = ('Segoe UI', 11, "bold"), background="#e6f0f0")
fill_arr_label = Label(text="Введите размерность массива: ", background="#e6f0f0", font = ('Segoe UI', 11))
fill_arr_entry = Entry(font = ('Segoe UI', 14))

exit_btn = Button(text='Выход', background="#79b8b7", font = ('Segoe UI', 14), padx=12,bd = 5, relief = RIDGE, command=root.destroy)
info_btn = Button(text='Справка', background="#79b8b7", font = ('Segoe UI', 14), padx=3,bd = 5, relief = RIDGE, command=info)

remove_duplicates_label.place(x = 10, y = 10)
dupl_arr_label.place(x = 10, y = 70)
dupl_arr_entry.place(x = 10, y = 110, height = 30, width = 570)
dupl_arr_entry.bind("<Return>", on_focus)

fill_fib_label.place(x = 10, y = 200)
fill_arr_label.place(x = 10, y = 250)
fill_arr_entry.place(x = 240, y = 250, height = 30, width = 100)

fill_arr_entry.bind("<Return>", on_focus)

canvas.place(x = 0, y = 0)

info_btn.place(x = 300, y = 300)
exit_btn.place(x = 180, y = 300)

root.mainloop()
