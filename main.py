import os
import subprocess

def list_files(directory):
    """列出指定目录下的所有文件和文件夹"""
    print("Files and folders in", directory)
    for item in os.listdir(directory):
        print(item)

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
        if os.name == 'nt':  # Windows系统
            os.startfile(file_path)
        else:
            subprocess.Popen(['xdg-open', file_path])  # 其他系统
        print("File", file_path, "opened successfully.")
    else:
        print("File", file_path, "does not exist.")

def main():
    while True:
        print("\nSimple File Management System")
        print("1. List files")
        print("2. Create file")
        print("3. Delete file")
        print("4. Open file")
        print("5. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            directory = input("Enter directory path: ")
            list_files(directory)
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
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == "__main__":
    main()
