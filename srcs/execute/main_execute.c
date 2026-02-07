#include "exec_run.h"

int main(void)
{
  t_mini *mini= build_echo_cat_wc();

//   redirection_center(mini);
//   cmd_path_center(mini, cmd); // 헷갈리쓰
  fork_center(mini);

  (void)(mini);
}