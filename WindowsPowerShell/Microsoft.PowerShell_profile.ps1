clear
cd C:\msys64\home\s0415
Remove-Variable -Force HOME
Set-Variable HOME "C:\msys64\home\s0415"
Set-alias -n "npp" "C:\Program Files\Notepad++\notepad++.exe"

$BASH = 1

Set-alias -n "npp" "C:\Users\s0415\AppData\Local\Programs\npp\notepad++.exe"
if ($BASH) {
    Set-alias -n "ls" "C:\msys64\usr\bin\ls"  -Option AllScope
    Set-alias -n "man" "C:\msys64\usr\bin\man"  -Option AllScope
}
function Prompt
{
    "$([char]27)[0mRoyChuang $([char]27)[31m" + "::" + "$([char]27)[32m $((Get-Location).Path)$([char]27)[34m" + "`n>> $([char]27)[0m"
}