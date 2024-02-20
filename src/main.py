import os
import directory_operations
import file_operations
import file_list
import file_utils

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
            file_list.list_files(current_directory)
        elif choice.lower() == 'ls':
            file_list.list_files(current_directory)
        elif choice == '2':
            file_path = input("Enter file path to create: ")
            file_operations.create_file(file_path)
        elif choice == '3':
            file_path = input("Enter file path to delete: ")
            file_operations.delete_file(file_path)
        elif choice == '4':
            file_path = input("Enter file path to open: ")
            file_operations.open_file(file_path)
        elif choice == '5':
            new_directory = input("Enter directory path: ")
            if new_directory == "cd":  # 如果输入为单独的 "cd"
                new_directory = "C:\\"  # 将目录设置为 "C:\"
            directory_operations.change_directory(new_directory)
            current_directory = os.getcwd()  # 更新当前目录
        elif choice == '6':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == "__main__":
    main()
