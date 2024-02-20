import os

def global_search(target_name):
    search_results = []
    for root, dirs, files in os.walk("/", topdown=True):
        for name in files:
            if target_name in name:
                search_results.append(os.path.join(root, name))
    return search_results
