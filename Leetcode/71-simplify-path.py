class Solution:
    def simplifyPath(self, path: str) -> str: 

        folders = path.split('/') 

        navigation_stack = []
        
        for folder in folders: 

            if folder == '.' or folder == '':
                continue
            elif folder == '..': 
                if navigation_stack: 
                    navigation_stack.pop()
            else: 
                navigation_stack.append(folder)

        canonical_path = '/' + '/'.join(navigation_stack) 

        return canonical_path