"""
使用字典设计一个公司组成结构的信息，该公司有五个部门(总经理办公室、人事部、财务部、
生产部、销售部)，每个部门有三名以上员工，每个员工有工号、姓名、性别、手机号基本信
息。要求能够通过字典键-值的映射，可以直接访问任一数据信息.
"""

import json

if __name__ == "__main__":
    with open("company.json", "r", encoding="utf-8") as fp:
        company = json.load(fp)
    company = dict(company)
    item = company.get(input("请输入要访问的部门:"))
    for clerk in item:
        print(clerk)
    Ttype = eval(input("请输入你要查询的数据类型:(0.姓名，1.工号，2.手机号)"))
    if Ttype == 0:
        clerk_name = input("请输入姓名：")
        for clerk in item:
            if clerk.get("姓名") == clerk_name:
                print(clerk)

    elif Ttype == 1:
        clerk_num = eval(input("请输入工号："))
        for clerk in item:
            if clerk.get("工号") == clerk_num:
                print(clerk)
    else:
        clerk_phonenum = eval(input("请输入手机号："))
        for clerk in item:
            if clerk.get("手机号") == clerk_phonenum:
                print(clerk)
