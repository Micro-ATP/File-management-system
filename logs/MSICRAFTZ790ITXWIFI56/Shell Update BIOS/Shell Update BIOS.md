【ENGLISH】

**Warning:** Updating BIOS is risky, please be careful. During the updating, do not interrupt the updating, power off, or restart, otherwise, the motherboard will not work.

**HOW TO UPDATE BIOS**

1. Prepare a USB storage device (formatted in FAT32 format), other boot disks such as PE or DOC cannot be used.

2. Visit MAXSUN support site at [www.maxsun.com.cn/en/](http://www.maxsun.com.cn/en/) to download and unzip the latest BIOS file.

3. Copy the entire extracted EFI folder to the root folder of the USB storage device you prepared.

4. Remove all hard drives (including M.2 and SATA SSD).

5. Insert your USB storage device into the USB port of the motherboard, press the "Delete" key repeatedly to enter the BIOS interface after power on.

6. Press “F9” and “Enter” to load optimized defaults. Then choose “Startup” and Disabled “Flash Write Protect”. Then press “F10” and “Enter” to save&reset.

7. Press the "F11" repeatedly and select the USB storage device boot option starting with UEFI.

8. The system will run to the UEFI boot shell interface, where the system will automatically execute the program to update the BIOS. The BIOS updating cannot be interrupted, otherwise, the motherboard will not work.

9. It will take about a few minutes, please wait.

10. When the screen displays “FS0:\EFI\BOOT>” or "FPT Operation Successful", unplug your USB storage device otherwise the system will repeat the update. Then press “Ctrl+Alt+Delete” at the same time and the system will automatically restart and enter the NEW BIOS.

11. In the new BIOS, press “F9” and “Enter” to load optimized defaults. Then press “F10” and “Enter” to save&reset.

---

【中文简体】

**温馨提示：** 更新BIOS有风险，请慎重，更新BIOS程序执行期间，请勿打断更新或断电重启，否则导致主板不亮机。

**更新BIOS步骤：**

1. 选择一个普通的U盘格式化成FAT32格式，不能使用PE或DOC等其他引导盘。

2. 将官网下载好的BIOS压缩包解压出来，将解压出的EFI文件夹整个拷贝到刷BIOS用的U盘根目录下。

3. 将U盘插入要刷BIOS的主板USB接口上，开机后按键盘Delete键进入主板BIOS界面。

4. 进入BIOS界面下的Startup模块下，将“Flash/BIOS Write Protect”功能设置为【Disabled】后，按F10确认保存重启。

5. 重启后不停按键盘的"F11"键进入主板的快捷引导界面，选择以UEFI开头的U盘启动选项。

6. 此时就会进入UEFI引导的shell界面，在该界面会自动执行刷写主板BIOS的程序，刷BIOS时不能打断刷写的过程，否则会导致主板开机不亮机。

7. 刷BIOS过程在几十秒钟到几分钟不等，请耐心等待。

8. 当主板有黄色字符FS0:\EFI\BOOT>出现后BIOS停止更新，或有绿色提升更新完成时，表示主板BIOS更新完成。

9. 更新完BIOS后的主板建议断掉AC供电，清除主板的CMOS信息后，再上电开机进BIOS，按F9加载优化值，按F10保存重启后再正常使用。
