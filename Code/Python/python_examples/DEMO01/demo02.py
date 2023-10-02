import json
from pyecharts.charts import Map
from pyecharts.options import VisualMapOpts, TitleOpts

f = open("D:/资料/可视化案例数据/地图数据/疫情.txt", "r", encoding="utf-8")
data = f.read()
f.close()

# 将字符串json转化为Python字典
data_dict = json.loads(data)
province_data_list = data_dict["areaTree"][0]["children"]
data_list = []
for province_data in province_data_list:
    province_name = province_data["name"]
    province_confirm = province_data["total"]["confirm"]
    data_list.append((province_name, province_confirm))

print(data_list)

map = Map()
map.add("各省份确诊人数", data_list, "china")
map.set_global_opts(
    title_opts=TitleOpts(title="全国疫情地图"),
    visualmap_opts=VisualMapOpts(
        is_show=True,
        is_piecewise=True,
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
map.render("全国疫情地图.html")
