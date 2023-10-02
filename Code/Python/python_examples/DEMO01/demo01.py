from pyecharts.charts import Map
from pyecharts.options import VisualMapOpts

map_china = Map()
data = [
    ("北京", 99),
    ("上海", 199),
    ("湖南", 299),
    ("台湾", 199),
    ("安徽", 299),
    ("广州", 399),
    ("湖北", 599)
]
map_china.add("map", data, "china")
map_china.set_global_opts(
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
map_china.render("中国地图.html")
