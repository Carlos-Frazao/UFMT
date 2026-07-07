import { Module } from '@nestjs/common';
import { TypeOrmModule } from '@nestjs/typeorm';
import { AuthModule } from '../auth/auth.module';
import { Personagem } from './entities/personagem.entity';
import { PersonagemController } from './personagem.controller';
import { PersonagemService } from './personagem.service';

@Module({
  imports: [TypeOrmModule.forFeature([Personagem]), AuthModule],
  controllers: [PersonagemController],
  providers: [PersonagemService],
})
export class PersonagemModule {}
