import os
import datetime
import readline
import sys
import stat

# 设置自动补全
def completer(text, state):
    current_directory = os.getcwd()
    os.chdir(current_directory)
    os.listdir('.')
    options = [i for i in os.listdir('.') if i.startswith(text)]
    if state < len(options):
        return options[state]
    else:
        return None

if sys.stdin.isatty():  # 检查是否在交互式环境中
    readline.set_completer(completer)
    readline.parse_and_bind("tab: complete")

# 列出文件详细信息
def list_files(directory):
    """列出指定目录下的所有文件和文件夹的详细信息"""
    print("Files and folders in", directory)
    for item in os.listdir(directory):
        item_path = os.path.join(directory, item)
        stat_info = os.stat(item_path)
        size = stat_info.st_size
        permissions = stat.filemode(stat_info.st_mode)
        modification_time = datetime.datetime.fromtimestamp(stat_info.st_mtime)
        print("{:<30} {:<10} {:<10} {:<30}".format(item, size, permissions, modification_time))


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

def change_directory(directory):
    """改变当前工作目录"""
    try:
        os.chdir(directory)
        print("Directory changed to", directory)
    except FileNotFoundError:
        print("Directory", directory, "does not exist.")
    except PermissionError:
        print("Permission denied to access", directory)

def main():
    current_directory = os.getcwd()
    while True:
        print("\nSimple File Management System")
        print("Current directory:", current_directory)
        print("1. List files")
        print("2. Create file")
        print("3. Delete file")
        print("4. Open file")
        print("5. Change directory")
        print("6. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            list_files(current_directory)
        elif choice == '2':
            file_path = input("Enter file path to create: ")
            create_file(file_path)
        elif choice == '3':
            file_path = input("Enter file path to delete: ")
            delete_file(file_path)
        elif choice == '4':
            file_path = input("Enter file path to open: ")
            open_file(file_path)
        elif choice == '5':
            new_directory = input("Enter directory path: ")
            if new_directory == "cd":  # 返回根目录
                current_directory = os.getcwd()
            else:
                change_directory(new_directory)
                current_directory = os.getcwd()
        elif choice == '6':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == "__main__":
    main()
