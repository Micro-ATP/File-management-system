import os

def change_directory(directory):
    """改变当前工作目录"""
    try:
        os.chdir(directory)
        print("Directory changed to", directory)
    except FileNotFoundError:
        print("Directory", directory, "does not exist.")
    except PermissionError:
        print("Permission denied to access", directory)