import subprocess

def open_diskpart_with_admin():
    try:
        # 使用subprocess模块打开diskpart命令行工具，并以管理员权限运行
        subprocess.Popen(['diskpart'], shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, bufsize=0, universal_newlines=True, creationflags=subprocess.CREATE_NEW_CONSOLE)
    except Exception as e:
        print("Error:", e)

