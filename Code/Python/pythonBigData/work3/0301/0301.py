import pandas as pd
import matplotlib.pyplot as plt
from pandas import DataFrame
import numpy as np
import matplotlib.ticker as ticker

# %%
plt.rcParams['font.family'] = 'SimHei'
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
# %%
# 读取数据
Co2_Data = pd.read_excel(r"D:\\pythonBigData\\work3\\0301\\HISCO2.xls", header=2)
GDP_Data = pd.read_excel(r"D:\\pythonBigData\\work3\\0301\\HISGDP.xlsx")
# %%
GDP_Data.replace("..", 0, inplace=True)
GDP_Data.dropna(inplace=True)
gdp = GDP_Data.iloc[:, 4:]
# print(type(gdp))
# print(gdp)

GDP_Data['gdpsum'] = gdp.sum(axis=1)
large_gdp_4 = GDP_Data["gdpsum"].sort_values(ascending=False)[1:6].index  # GDP前四的国家和地区(排除world总共的和OEC)
# print(large_gdp_4)
# print(GDP_Data.iloc[large_gdp_4.tolist()])
country_code = GDP_Data.iloc[large_gdp_4.tolist()]['Country Code'].tolist()
country_code.remove('OEC')
# print(country_code)  #['HIC', 'OED', 'ECS', 'NAC']
gdp_4_index = []
for item in country_code:
    gdp_4_index.append(GDP_Data[GDP_Data['Country Code'] == item].index.item())
gdp_4_all = GDP_Data.iloc[gdp_4_index, :-2]
gdp_4 = gdp_4_all.iloc[:, 4:].values  # GDP前四的国家和地区，是个二维数组
gdp_4 /= 1e13  # 归一化处理
# print(gdp_4)
# %%
Co2_Data.drop_duplicates(inplace=True)
Co2_Data.columns = Co2_Data.loc[0]
Co2_Data.drop(0, inplace=True)
Co2_Data.reset_index(inplace=True, drop=True)
# print(Co2_Data.columns)
gdp_4_co2_index = []
for item in country_code:
    gdp_4_co2_index.append(Co2_Data[Co2_Data['Country Code'] == item].index.item())
# print(gdp_4_co2_index)
gdp_4_co2_all: DataFrame = Co2_Data.iloc[gdp_4_co2_index, :-3]  # 删除后三列
gdp_4_co2_all.interpolate(method='linear', axis=0, inplace=True)  # 插值填充空缺值
# print(gdp_4_co2_all['Country Name'])  # 高收入国家 经合组织成员 欧洲与中亚地区  北美
gdp_4_co2 = gdp_4_co2_all.iloc[:, 4:].values  # 前四GDP的国家的CO2排放
gdp_4_co2 /= 1e6  # 归一化处理
# print(gdp_4_co2)
# %%
years = GDP_Data.columns.tolist()[4:-2]
years = [num[:4] for num in years]
years = np.array(years, dtype=int)
years_ticks = range(years[0], years[-1], 5)
# print(years)
# %%
plt.figure(figsize=(14, 10))
plt.title('二氧化碳排放&GDP表(全球GDP前四)')
plt.xlabel('年份')
plt.ylabel('CO2及GDP')

plt.plot(years, gdp_4[0], 'g', label='高收入国家GDP')
plt.plot(years, gdp_4_co2[0], 'g--', label='高收入国家CO2排放')

plt.plot(years, gdp_4[1], 'r', label='经合组织成员GDP')
plt.plot(years, gdp_4_co2[1], 'r--', label='经合组织成员CO2排放')

plt.plot(years, gdp_4[2], 'b', label='欧洲与中亚地区GDP')
plt.plot(years, gdp_4_co2[2], 'b--', label='欧洲与中亚地区CO2排放')

plt.plot(years, gdp_4[3], 'y', label='北美GDP')
plt.plot(years, gdp_4_co2[3], 'y--', label='北美CO2排放')
plt.xticks(years_ticks)
plt.legend()
plt.savefig(r'gdp_4_co2.jpg')
plt.show()
# %%
bricks = ['BRA', 'IND', 'RUS', 'CHN', 'ZAF']  # 巴西 、  印度 、俄罗斯 、 中国 、 南非 金砖五国
bricks_gdp_index = []
for item in bricks:
    bricks_gdp_index.append(GDP_Data[GDP_Data['Country Code'] == item].index.item())
# print(bricks_index)
# print(GDP_Data.iloc[bricks_gdp_index,:-2])
gdp_bricks: DataFrame = GDP_Data.iloc[bricks_gdp_index, 4:-2]  # 删除后两列和前四列
gdp_bricks.replace(0, np.nan, inplace=True)
gdp_bricks.interpolate(method='linear', inplace=True)
gdp_bricks_list = gdp_bricks.values
gdp_bricks_list /= 1e10
# print(type(gdp_bricks_list))
print(gdp_bricks_list)
# %%
bricks_co2_index = []
for item in bricks:
    bricks_co2_index.append(Co2_Data[Co2_Data['Country Code'] == item].index.item())
# print(bricks_co2_index)
# print(Co2_Data.iloc[bricks_co2_index,:-3])
co2_bricks: DataFrame = Co2_Data.iloc[bricks_co2_index, 4:-3]  # 去除后三列和前四列
co2_bricks.interpolate(method='linear', inplace=True)
co2_bricks_list = co2_bricks.values
co2_bricks_list /= 1e4
# print(co2_bricks_list)
# %%
plt.figure(figsize=(14, 10))
plt.title('二氧化碳排放&GDP表(金砖五国)')
plt.xlabel('年份')
plt.ylabel('CO2及GDP')

plt.plot(years, gdp_bricks_list[0], 'g', label='巴西GDP')
plt.plot(years, co2_bricks_list[0], 'g--', label='巴西CO2排放')

plt.plot(years, gdp_bricks_list[1], 'r', label='印度GDP')
plt.plot(years, co2_bricks_list[1], 'r--', label='印度CO2排放')

plt.plot(years, gdp_bricks_list[2], 'b', label='俄罗斯GDP')
plt.plot(years, co2_bricks_list[2], 'b--', label='俄罗斯CO2排放')

plt.plot(years, gdp_bricks_list[3], 'y', label='中国GDP')
plt.plot(years, co2_bricks_list[3], 'y--', label='中国CO2排放')

plt.plot(years, gdp_bricks_list[4], 'm', label='南非GDP')
plt.plot(years, co2_bricks_list[4], 'm--', label='南非CO2排放')

plt.xticks(years_ticks)
plt.legend()
plt.savefig(r'gdp_bricks_co2.jpg')
plt.show()
# %%
africa_5_gdp_index = []
africa_5 = ['NGA', 'ZAF', 'EGY', 'DZA', 'MAR']  # 尼日利亚,南非，埃及，阿尔及利亚，摩洛哥
for item in africa_5:
    africa_5_gdp_index.append(GDP_Data[GDP_Data['Country Code'] == item].index.item())
# print(africa_5_gdp_index)
# print(GDP_Data.iloc[africa_5_gdp_index,:-2])
gdp_5_africa: DataFrame = GDP_Data.iloc[africa_5_gdp_index, 4:-2]  # 删除后两列和前四列
gdp_5_africa.replace(0, np.nan, inplace=True)
gdp_5_africa.interpolate(method='linear', inplace=True)
gdp_afirca_list = gdp_5_africa.values
gdp_afirca_list /= 1e10
# print(type(gdp_bricks_list))
# print(gdp_afirca_list)
# %%
africa_co2_index = []
for item in africa_5:
    africa_co2_index.append(Co2_Data[Co2_Data['Country Code'] == item].index.item())
# print(bricks_co2_index)
# print(Co2_Data.iloc[africa_co2_index,:-3])
co2_africa: DataFrame = Co2_Data.iloc[bricks_co2_index, 4:-3]  # 去除后三列和前四列
co2_africa.interpolate(method='linear', inplace=True)
co2_africa_list = co2_africa.values
co2_africa_list /= 1e4
# print(co2_bricks_list)
# %%
plt.figure(figsize=(14, 10))
plt.title('二氧化碳排放&GDP表(非洲前五)')  # 尼日利亚,南非，埃及，阿尔及利亚，摩洛哥
plt.xlabel('年份')
plt.ylabel('CO2及GDP')

plt.plot(years, gdp_afirca_list[0], 'g', label='尼日利亚GDP')
plt.plot(years, co2_africa_list[0], 'g--', label='尼日利亚CO2排放')

plt.plot(years, gdp_afirca_list[1], 'r', label='南非GDP')
plt.plot(years, co2_africa_list[1], 'r--', label='南非CO2排放')

plt.plot(years, gdp_afirca_list[2], 'b', label='埃及GDP')
plt.plot(years, co2_africa_list[2], 'b--', label='埃及CO2排放')

plt.plot(years, gdp_afirca_list[3], 'y', label='阿尔及利亚GDP')
plt.plot(years, co2_africa_list[3], 'y--', label='阿尔及利亚CO2排放')

plt.plot(years, gdp_afirca_list[4], 'm', label='摩洛哥GDP')
plt.plot(years, co2_africa_list[4], 'm--', label='摩洛哥CO2排放')

plt.xticks(years_ticks)
plt.legend()
plt.savefig(r'gdp_africa_co2.jpg')
plt.show()
