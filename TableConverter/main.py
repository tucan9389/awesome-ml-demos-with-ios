# Copyright 2019 Doyoung Gwak (tucan.dev@gmail.com)
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ======================
#-*- coding: utf-8 -*-



dict = {}
device_name = None
device_names = []

f = open("performance-classification.txt", 'r')
lines = f.readlines()
for line in lines:
    componants = line.split()
    # if len(componants) == 0:

    if len(componants) == 0:
        continue

    if len(componants) != 5:
        device_name = " ".join(componants)
        device_names.append(device_name)
        continue
    else:
        model_name = componants[0]
        inference_time = componants[2]
        total_time = componants[3]
        fps = componants[4]

        if model_name not in dict:
            dict[model_name] = {}

        dict[model_name][device_name] = {
            "inference_time": inference_time,
            "total_time": total_time,
            "fps": fps
        }
f.close()




def get_markdown_table(dict, colunm_name = "inference_time"):
    result = ""

    row_text = "| Model vs. Device | "
    row_text = row_text + " | ".join(device_names)
    row_text = row_text + " |"
    result += row_text + "\n"
    # print(row_text)

    row_text = "| ---- | "
    for i in range(len(device_names)):
        row_text += "---- | "
    result += row_text + "\n"
    # print(row_text)

    for model_name in dict.keys():
        row_text = "| " + model_name + " | "
        for device_name in device_names:
            row_text += dict[model_name][device_name][colunm_name] + " | "
        result += row_text + "\n"

    return result

# inference_time
# total_time
# fps

print()
print()
print()

print("## Object Detection")
print()

print("### Infernece Time (ms)")
print()
print(get_markdown_table(dict=dict, colunm_name="inference_time"))

print("### Total Time (ms)")
print()
print(get_markdown_table(dict=dict, colunm_name="total_time"))

print("### FPS")
print()
print(get_markdown_table(dict=dict, colunm_name="fps"))