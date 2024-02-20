import os
import directory_operations
import file_operations
import file_list
import whereis

def main():
    while True:
        current_directory = os.getcwd()
        prompt = f"atp@ATP_Shell ~{current_directory} ~> "
        print("Welcome to ATP_Shell, the friendly interactive shell")
        print("Type help for instructions on how to use ATP_Shell")

        choice = input(prompt)
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
        elif choice.startswith('cd '):  # 用户输入以 "cd " 开头
            new_directory = choice[3:]  # 提取路径
            directory_operations.change_directory(new_directory)
            current_directory = os.getcwd()  # 更新当前目录
        elif choice == 'cd':  # 如果用户只输入 "cd"
            new_directory = "C:\\"  # 默认将目录更改为 "C:\"
            directory_operations.change_directory(new_directory)
            current_directory = os.getcwd()  # 更新当前目录
        elif choice.startswith('whereis '):
            target_name = choice[8:]  # 提取文件名
            search_results = whereis.global_search(target_name)  # 调用 whereis 模块的全局搜索功能
            if search_results:
                print("Search results:")
                for result in search_results:
                    print(result)
            else:
                print("No matching files found.")
        elif choice == '0' or choice.lower() == 'exit' or choice.lower() == 'quit':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == "__main__":
    main()
