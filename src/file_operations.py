import os

def create_file(file_path):
    """创建一个新文件"""
    with open(file_path, 'w') as f:
        pass
    print("File", file_path, "created successfully.")

def delete_file(file_path):
    """删除指定文件"""
    if os.path.exists(file_path):
        os.remove(file_path)
        print("File", file_path, "deleted successfully.")
    else:
        print("File", file_path, "does not exist.")

def open_file(file_path):
    """使用默认应用程序打开指定文件"""
    if os.path.exists(file_path):
        if os.path.isfile(file_path):
            os.startfile(file_path) if os.name == 'nt' else os.system('xdg-open ' + file_path)
            print("File", file_path, "opened successfully.")
        else:
            print("Not a valid file.")
    else:
        print("File", file_path, "does not exist.")
