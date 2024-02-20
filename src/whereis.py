import os

def global_search(target_name):
    search_results = []
    for root, dirs, files in os.walk("/", topdown=True):
        for name in files:
            if target_name in name:
                search_results.append(os.path.join(root, name))
    return search_results

# import os
# import subprocess

# def global_search(target_name):
#     try:
#         # 调用 Everything 的命令行接口进行搜索
#         command = r'"C:\\Program Files\\Everything\\Everything.exe" - "{}"'.format(target_name)
#         output = subprocess.check_output(command, shell=True, encoding='utf-8')

#         # 解析搜索结果
#         search_results = output.strip().split('\n')
#         return search_results
#     except Exception as e:
#         print("Error:", e)
#         return []


