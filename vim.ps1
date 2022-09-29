param
(
    [string]$file = $args[0]
)

start powershell -ArgumentList cd, $pwd, ";", vim.exe, "$pwd/$file"
