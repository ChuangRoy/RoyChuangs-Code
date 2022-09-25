param($Work)

# restart PowerShell with -noexit, the same script, and 1
if (!$Work) {
    powershell -noexit -file $MyInvocation.MyCommand.Path 1
    return
}


$script:THIS_PATH = $myinvocation.mycommand.path
$script:BASE_DIR = Split-Path (Resolve-Path "$THIS_PATH") -Parent

cd $BASE_DIR