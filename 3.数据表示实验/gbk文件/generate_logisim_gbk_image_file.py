# -*- coding: utf-8 -*-
import os
def main():
    path = input("请输入文本文件所在文件夹路径(例如C:\pathA\pathB)：")
    filename = input("输入文件名(包括后缀,例如school.txt)：")
    os.chdir(path)
    f = open(filename, 'r', encoding='gbk')
    o = open("gbk_img_file.txt", "w", encoding="gbk")
    o.write("v2.0 raw\n")
    for i in f.read():
        i_gbk = i.encode("gbk")
        char0 = hex(i_gbk[0])
        if len(i_gbk) == 2:
            o.write(char0[2:4] if len(char0) == 4 else char0[2])
            char1 = hex(i_gbk[1])
            o.write(char1[2:4] if len(char1) == 4 else char1[2])
        else:
            o.write(char0[2:4] if len(char0) == 4 else char0[2])
        o.write("\n")
    o.close()
    f.close()
    print("生成成功！文件名为gbk_img_file.txt")

if __name__ == "__main__":
    main()