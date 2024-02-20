import subprocess

def open_urwtest_v18():
    # urwtest_v18.exe的路径
    urwtest_exe_path = r"E:\\GitHub\\File-management-system\src\\urwtest_v18.exe"
    try:
        # 启动urwtest_v18.exe，使用Popen函数
        subprocess.Popen(urwtest_exe_path)
        print("urwtest_v18.exe 已成功启动。")
    except Exception as e:
        print("启动 urwtest_v18.exe 时发生错误:", e)

