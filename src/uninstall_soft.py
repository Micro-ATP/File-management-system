import subprocess

def uninstall_software(software_name):
    try:
        # 使用wmic命令卸载指定的软件
        subprocess.run(['wmic', 'product', 'where', f'name="{software_name}"', 'uninstall'], check=True)
        print(f"{software_name} has been uninstalled successfully.")
    except subprocess.CalledProcessError as e:
        print(f"Failed to uninstall {software_name}. Error: {e}")

# 调用示例
uninstall_software("YourSoftwareName")
