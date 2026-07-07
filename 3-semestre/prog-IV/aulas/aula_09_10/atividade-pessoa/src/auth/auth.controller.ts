import { Controller, Post, Body, HttpCode, HttpStatus } from '@nestjs/common';
import { AuthService } from './auth.service';

@Controller('auth')
export class AuthController {
  constructor(private readonly authService: AuthService) {}

  @HttpCode(HttpStatus.OK)
  @Post('login')
  login(@Body() body: Record<string, any>) {
    // Pega o e-mail e a senha que vieram na requisição e manda pro Service
    return this.authService.login(body.email, body.senha);
  }
}