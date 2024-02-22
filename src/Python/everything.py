from everytools import EveryTools

def search_files(keyword):
    """
    Function to search for files using the everytools library.

    Parameters:
        keyword (str): The keyword to search for.

    Returns:
        list: A list of dictionaries containing search results, each dictionary contains 'name' and 'path'.
    """
    # 创建 EveryTools 实例
    es = EveryTools()
    # 使用关键字搜索文件
    es.search(keyword)
    # 获取搜索结果
    results = es.results()

    # 将DataFrame转换为字典列表
    search_results = []
    for index, row in results.iterrows():
        search_results.append({'name': row['name'], 'path': row['path']})

    return search_results
