from file_utils import convert_size, get_permissions

def list_files(directory):
    """列出指定目录下的所有文件和文件夹的详细信息"""
    print("{:<30} {:<15} {:<10} {:<30}".format("Name", "Size", "Permissions", "Modification Time"))
    print("=" * 80)  # 添加分隔线
    for item in os.listdir(directory):
        item_path = os.path.join(directory, item)
        size = convert_size(os.path.getsize(item_path))
        permissions = get_permissions(item_path)
        modification_time = datetime.datetime.fromtimestamp(os.path.getmtime(item_path))
        print("{:<30} {:<15} {:<10} {:<30}".format(item, size, permissions, modification_time))
