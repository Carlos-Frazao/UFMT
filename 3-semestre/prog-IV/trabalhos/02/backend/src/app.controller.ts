import { Controller, Get } from '@nestjs/common';

@Controller()
export class AppController {
  @Get()
  getStatus() {
    return { mensagem: 'API Wiki Mr. Robot - Trabalho 02' };
  }
}
