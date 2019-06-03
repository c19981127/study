from Crypto.Cipher import AES
from binascii import b2a_hex,a2b_hex
from tkinter import *
#if test is less then 16 then add 0
def add_to_16(text):
    if len(text.encode('utf-8'))%16:
        add = 16 - (len(text.encode('utf-8'))%16)
    else:
        add = 0
    text = text + ('\0' * add)
    return text.encode('utf-8')
#code function
def encrypt(text):
    key = '9999999999999999'.encode('utf-8')
    mode = AES.MODE_CBC
    iv = 'qqqqqqqqqqqqqqqq'
    text = add_to_16(text)
    cryptos = AES.new(key,mode,iv);
    cipher_text = cryptos.encrypt(text);
    return b2a_hex(cipher_text)

#decode function
def decrypt(text):
    key = '9999999999999999'.encode('utf-8')
    iv = 'qqqqqqqqqqqqqqqq'
    mode = AES.MODE_CBC
    cryptos = AES.new(key,mode,iv)
    plain_text = cryptos.decrypt(a2b_hex(text))
    return bytes.decode(plain_text).rstrip('\0')
#init the windows and operation
def init_window():
    windows = Tk();
    windows.title("AES")
    windows.geometry("235x180")
    windows.resizable(width=False,height=False)
    frm_main = Frame(windows)
    frm_top = Frame(frm_main)
    frm_little = Frame(frm_main)
    frm_little_top = Frame(frm_little)
    frm_little_bottom = Frame(frm_little)
    string = Label(frm_top,text="string",bg="pink",font=("Arial",12),width=6,height=1)
    string_text = Text(frm_top,font=("Arial",12),width = 20,height = 1)
    code = Label(frm_little_top,text="code",bg="pink",font=("Arial",12),width=6,height=1)
    code_text = Text(frm_little_top,font=("Arial",12),width = 20,height = 5)
    decode = Label(frm_little_bottom,text="decode",bg="pink",font=("Arial",12),width=6,height=1)
    decode_text = Text(frm_little_bottom,font=("Arial",12),width = 20,height = 1)
    #encrypt the string you have entered
    def action():
        code_text.delete("1.0","end")
        decode_text.delete("1.0","end")
        code_text.insert('1.0',encrypt(string_text.get("1.0","end")))
        decode_text.insert('1.0',decrypt(code_text.get("1.0","end").strip('\n')))
    def encrypt_file():
        file = open("string.txt",'r')
        s = bytes.decode(encrypt(file.read()))
        file.close()
        file_again= open("string.txt",'w')
        file_again.write(s)
        file_again.close()
        print("Code successful")
    def dencrypt_file():
        file = open("string.txt",'r')
        s = decrypt(file.read())
        file.close()
        file_again= open("string.txt",'w')
        file_again.write(s)
        file_again.close()
        print("decode successful")
    string.pack(side=LEFT)
    string_text.pack(side=LEFT)
    code.pack(side=LEFT)
    code_text.pack(side=LEFT)
    decode.pack(side=LEFT)
    decode_text.pack(side=LEFT)
    frm_top.pack(side=TOP)
    frm_little_top.pack(side=TOP)
    frm_little_bottom.pack(side=TOP)
    frm_little.pack(side=TOP)
    frm_main.pack()
    Button(windows, text="press", command=action).pack(side=LEFT)
    Button(windows, text="CodeFile", command=encrypt_file).pack(side=LEFT)
    Button(windows, text="DecodeFile", command=dencrypt_file).pack(side=LEFT)
    windows.mainloop()

if __name__ == '__main__':
    init_window()
