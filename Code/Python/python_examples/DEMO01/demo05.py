from pyecharts.charts import Bar, Timeline
from pyecharts.options import LabelOpts
bar1 = Bar()
bar1.add_xaxis(["中国", "美国", "英国"])
bar1.add_yaxis("GDP", [30, 20, 10], label_opts=LabelOpts(position="right"))

# bar.reversal_axis()
bar1.render("基础柱状图.html")
bar2 = Bar()
bar2.add_xaxis(["中国", "美国", "英国"])
bar2.add_yaxis("GDP", [50, 30, 20], label_opts=LabelOpts(position="right"))
bar2.render("基础柱状图.html")
bar3 = Bar()
bar3.add_xaxis(["中国", "美国", "英国"])
bar3.add_yaxis("GDP", [70, 60, 25], label_opts=LabelOpts(position="right"))
bar3.render("基础柱状图.html")

timeline = Timeline()
timeline.add(bar1, "点1")
timeline.add(bar2, "点2")
timeline.add(bar3, "点3")

timeline.add_schema(
    play_interval=1000,
    is_timeline_show=True,
    is_auto_play=True,
    is_loop_play=True
)

timeline.render("GDP动态变化.html")
