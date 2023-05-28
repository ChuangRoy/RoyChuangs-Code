$script:THIS_PATH = $myinvocation.mycommand.path
$script:BASE_DIR = Split-Path (Resolve-Path "$THIS_PATH") -Parent

function global:prompt
    {
    "$([char]27)[32m$((Get-Location).Path)" + "`n>>"
    }

$env:PATH = "$BASE_DIR/mingw64/bin;" + $env:PATH
