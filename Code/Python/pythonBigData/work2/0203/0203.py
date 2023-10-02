"""
统计一段英文文章中每个字母（区分大小写）及数字的字符的个数，以字典形式表示，键为字母或数字，
值为数量。英文文章可用文本编辑器打开，复制粘贴到Python中，写成三引号多行字符串。
"""

str1 = """"
        Gary Steinman, an obstetrician at New York's Long Island Jewish Medical 
        Center, compared the heights of 129 women who gave birth to twins or triplets 
        with the average height of women in the United States and found women with 
        multiple-birth pregnancies averaged more than an inch talle.
        In a previous study, Steinman found that women who consume animal 
        products, specifically dairy, were five times more likely to have twins. Cows, like 
        humans, produce-insulin-like growth factor in response to growth hormones and 
        release it into the blood, and the protein makes its way into their milk.
        123 5 46 98756 32 156478 954 22 54 66987 557
"""
if __name__ == '__main__':
    a_dict = {}
    for ch in str1:
        if ch.isdigit() or ch.isalpha():
            cnt = str1.count(ch)
            a_dict[ch] = cnt

    print(a_dict)
