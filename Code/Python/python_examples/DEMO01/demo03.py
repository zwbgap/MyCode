import json
from pyecharts.charts import Map
from pyecharts.options import VisualMapOpts, TitleOpts
f = open("D:/资料/可视化案例数据/地图数据/疫情.txt", "r", encoding="utf-8")
data = f.read()
f.close()

# 将字符串json转化为Python字典
data_dict = json.loads(data)
cities_data_list = data_dict["areaTree"][0]["children"][3]["children"]
data_list = []
for cities_data in cities_data_list:
    city_name = cities_data["name"] + "市"
    city_confirm = cities_data["total"]["confirm"]
    data_list.append((city_name, city_confirm))

print(data_list)
# 手动添加数据
data_list.append(("济源市", 5))

map = Map()
map.add("河南省确诊人数", data_list, "河南")
map.set_global_opts(
    title_opts=TitleOpts(title="河南疫情地图"),
    visualmap_opts=VisualMapOpts(
        is_show=True,  # 是否显示
        is_piecewise=True,  # 是否分段
        pieces=[
            {"min": 1, "max": 9, "label": "1-9", "color": "#CCFFFF"},
            {"min": 10, "max": 99, "label": "10-99", "color": "#FF9999"},
            {"min": 100, "max": 499, "label": "100-499", "color": "#FF9966"},
            {"min": 500, "max": 999, "label": "500-999", "color": "#FF6666"},
            {"min": 1000, "max": 9999, "label": "1000-9999", "color": "#CC3333"},
            {"min": 10000, "label": ">=10000", "color": "#990033"}
        ]
    )
)
map.render("河南省疫情地图.html")

