import subprocess

def get_installed_software():
    try:
        # 使用wmic命令获取已安装的软件列表，输出结果到stdout并解码为utf-8
        output = subprocess.check_output(['wmic', 'product', 'get', 'name'], universal_newlines=True)
        # 将输出按行拆分，并排除空行和表头
        software_list = [line.strip() for line in output.split('\n') if line.strip() and line.strip() != 'Name']
        return software_list
    except Exception as e:
        print("Error:", e)
        return None

def main():
    installed_software = get_installed_software()
    if installed_software:
        print("Installed software:")
        for software in installed_software:
            print(software)

if __name__ == "__main__":
    main()
