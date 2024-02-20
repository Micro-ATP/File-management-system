import os
import directory_operations
import file_operations
import file_list
import whereis
import fetch_soft
import uninstall_soft
import help
import clear
import diskpart
import everything
import chkssd
import readline

def main():
    # 设置默认路径为 "C:\\"
    os.chdir("C:\\")
    readline.parse_and_bind('tab: complete')
    print("Welcome to ATP_Shell, the friendly interactive shell")
    print("Type help for instructions on how to use ATP_Shell")
    
    while True:
        current_directory = os.getcwd()
        prompt = f"atp@ATP_Shell ~{current_directory} ~> "
        choice = input(prompt)
        if choice.lower() == 'ls':
            file_list.list_files(current_directory)
        elif choice.startswith('touch '):
            file_path = choice[6:]
            file_operations.create_file(file_path)
        elif choice.startswith('rm -f '):
            file_path = choice[6:]
            file_operations.delete_file(file_path)
        elif choice.startswith('open '):
            file_path = choice[5:]
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
        elif choice == 'neofetch':
            print("""
             .-/+oossssoo+/-.               atp@ATP_Shell
        `:+ssssssssssssssssss+:`           -----------
      -+ssssssssssssssssssyyssss+-         OS: Microsoft Windows 11 专业版 64 位
    .ossssssssssssssssssdMMMNysssso.       Kernel: 10.0.22631
   /ssssssssssshdmmNNmmyNMMMMhssssss/      Uptime: 11d 4h 51m 4s
  +ssssssssshmydMMMMMMMNddddyssssssss+     Motherboard: ROG MAXIMUS Z790 FORMULA D5
 /sssssssshNMMMyhhyyyyhmNMMMNhssssssss/    Shell: ATP_Shell 
.ssssssssdMMMNhsssssssssshNMMMdssssssss.   Packages: 991 (dpkg), 6 (snap)
+sssshhhyNMMNyssssssssssssyNMMMysssssss+   Resolution: 7680 x 4320
ossyNMMMNyMMhsssssssssssssshmmmhssssssso   Font: Segoe UI
ossyNMMMNyMMhsssssssssssssshmmmhssssssso   CPU: 14th Gen Intel(R) Core(TM) i9-14900KS
+sssshhhyNMMNyssssssssssssyNMMMysssssss+   GPU: NVIDIA RTX™ 6000 Ada
 /sssssssshNMMMyhhyyyyhdNMMMNhssssssss/    RAM: 130,944MB / 25038 MB (19%)
  +sssssssssdmydMMMMMMMMddddyssssssss+     Disk C: 330GB / 4,096GB (8%)
   /ssssssssssshdmNNNNmyNMMMMhssssss/      Disk D: 1609GB / 4,096GB (39%)
    .ossssssssssssssssssdMMMNysssso.
      -+sssssssssssssssssyyyssss+-
        `:+ssssssssssssssssss+:`
            .-/+oossssoo+/-.
                  """)
        elif choice == 'fetchsoft':
            installed_software = fetch_soft.get_installed_software()
            if installed_software is not None:
                print("Installed software:")
                for software in installed_software:
                    print(software)
            else:
                print("Failed to retrieve the number of installed software.")
        elif choice.startswith('unsoft '):
            software_name = choice[7:]  # 提取软件名称
            uninstall_soft.uninstall_software(software_name)
        elif choice == 'help':
            help.help_log()
        elif choice.lower() == 'clear':
            clear.clear_screen()
        elif choice == 'diskpart':
            diskpart.open_diskpart_with_admin()
        elif choice.startswith('everything '):
            keyword = choice[11:]  # 提取搜索关键词
            search_results = everything.search_files(keyword)
            print("Everything search results:")
            print("Total results:", len(search_results))
            for i, result in enumerate(search_results[:5], 1):
                print(f"{i}. Name: {result['name']}, Path: {result['path']}")
        elif choice == 'chkssd':
            chkssd.open_urwtest_v18()
        elif choice.lower() == 'exit' or choice.lower() == 'quit':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please enter a valid option. If you need help, type 'help' and press Enter.")

if __name__ == "__main__":
    main()
