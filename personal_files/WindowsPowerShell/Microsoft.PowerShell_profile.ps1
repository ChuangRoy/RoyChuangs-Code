clear
Set-alias -n "npp" "C:\Program Files\Notepad++\notepad++.exe"

function Prompt
{
    "$([char]27)[0mRoyChuang $([char]27)[31m" + "::" + "$([char]27)[32m $((Get-Location).Path)$([char]27)[34m" + "`n>> $([char]27)[0m"
}